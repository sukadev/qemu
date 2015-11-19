/*
 * QEMU sPAPR PCI host for VFIO
 *
 * Copyright (c) 2011-2014 Alexey Kardashevskiy, IBM Corporation.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License,
 *  or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "hw/ppc/spapr.h"
#include "hw/pci-host/spapr.h"
#include "qemu/error-report.h"

#define TYPE_SPAPR_PCI_VFIO_HOST_BRIDGE "spapr-pci-vfio-host-bridge"

#define SPAPR_PCI_VFIO_HOST_BRIDGE(obj) \
    OBJECT_CHECK(sPAPRPHBVFIOState, (obj), TYPE_SPAPR_PCI_VFIO_HOST_BRIDGE)

typedef struct sPAPRPHBVFIOState sPAPRPHBVFIOState;

struct sPAPRPHBVFIOState {
    sPAPRPHBState phb;

    int32_t iommugroupid;
};

static Property spapr_phb_vfio_properties[] = {
    DEFINE_PROP_INT32("iommu", sPAPRPHBVFIOState, iommugroupid, -1),
    DEFINE_PROP_END_OF_LIST(),
};

static void spapr_phb_vfio_instance_init(Object *obj)
{
    error_report("spapr-pci-vfio-host-bridge is deprecated");
}

static void spapr_phb_vfio_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->props = spapr_phb_vfio_properties;
}

static const TypeInfo spapr_phb_vfio_info = {
    .name          = TYPE_SPAPR_PCI_VFIO_HOST_BRIDGE,
    .parent        = TYPE_SPAPR_PCI_HOST_BRIDGE,
    .instance_size = sizeof(sPAPRPHBVFIOState),
    .instance_init = spapr_phb_vfio_instance_init,
    .class_init    = spapr_phb_vfio_class_init,
};

static void spapr_pci_vfio_register_types(void)
{
    type_register_static(&spapr_phb_vfio_info);
}

type_init(spapr_pci_vfio_register_types)
