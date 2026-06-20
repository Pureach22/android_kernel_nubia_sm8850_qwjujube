__int64 sensors_sensitivity_register()
{
  __int64 v0; // x0
  __int64 v1; // x8
  unsigned __int64 v2; // x0
  __int64 v3; // x8
  unsigned __int64 v4; // x0
  _QWORD *v5; // x8
  unsigned int sysfs_interfaces; // w0
  unsigned int v7; // w0
  unsigned int v9; // w24
  __int64 v10; // x21
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x1

  if ( SENSORS_SENS_LOG_LEVEL >= 2 )
    printk(&unk_75D0, "NUBIA_SENSORS_SENS", "sensors_sensitivity_register", 343);
  v0 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96);
  sensors_sens_data = v0;
  if ( !v0 )
  {
    printk(&unk_782F, "NUBIA_SENSORS_SENS", "sensors_sensitivity_register", 347);
    return 4294967284LL;
  }
  _mutex_init(v0 + 16, "&sensors_sens_data->sensors_sens_lock", &sensors_sensitivity_register___key);
  v1 = sensors_sens_data;
  *(_BYTE *)(sensors_sens_data + 64) = 0;
  *(_QWORD *)(v1 + 68) = 0x6400000064LL;
  *(_DWORD *)(v1 + 76) = 100;
  *(_BYTE *)(v1 + 80) = 0;
  *(_QWORD *)(v1 + 84) = 0x6400000064LL;
  *(_DWORD *)(v1 + 92) = 100;
  sensors_sens_class = class_create("sensors_sensitivity");
  alloc_chrdev_region(&sensors_accel_dev_t, 0, 1, "accel");
  v2 = device_create(sensors_sens_class, 0, (unsigned int)sensors_accel_dev_t, 0, "accel");
  v3 = sensors_sens_data;
  *(_QWORD *)sensors_sens_data = v2;
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_745A, "NUBIA_SENSORS_SENS", "sensors_sensitivity_register", 368);
    v9 = 0;
LABEL_18:
    *(_QWORD *)sensors_sens_data = 0;
    device_destroy(sensors_sens_class, (unsigned int)sensors_accel_dev_t);
    class_destroy(sensors_sens_class);
    return v9;
  }
  *(_QWORD *)(v2 + 152) = v3;
  alloc_chrdev_region(&sensors_gyro_dev_t, 0, 1, "gyro");
  v4 = device_create(sensors_sens_class, 0, (unsigned int)sensors_gyro_dev_t, 0, "gyro");
  v5 = (_QWORD *)sensors_sens_data;
  *(_QWORD *)(sensors_sens_data + 8) = v4;
  if ( v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_745A, "NUBIA_SENSORS_SENS", "sensors_sensitivity_register", 377);
    v9 = 0;
LABEL_17:
    v12 = sensors_sens_class;
    v13 = (unsigned int)sensors_gyro_dev_t;
    *(_QWORD *)(sensors_sens_data + 8) = 0;
    device_destroy(v12, v13);
    class_destroy(sensors_sens_class);
    goto LABEL_18;
  }
  *(_QWORD *)(v4 + 152) = v5;
  sysfs_interfaces = sensor_create_sysfs_interfaces(*v5, &attrs_sensors_sens_accel_device);
  if ( (sysfs_interfaces & 0x80000000) != 0 )
  {
    v9 = sysfs_interfaces;
    printk(&unk_766D, "NUBIA_SENSORS_SENS", "sensors_sensitivity_register", 384);
LABEL_16:
    v11 = *(_QWORD *)sensors_sens_data;
    device_remove_file(*(_QWORD *)sensors_sens_data, &attrs_sensors_sens_accel_device);
    device_remove_file(v11, &off_38);
    device_remove_file(v11, &off_58);
    device_remove_file(v11, &off_78);
    goto LABEL_17;
  }
  v7 = sensor_create_sysfs_interfaces(*(_QWORD *)(sensors_sens_data + 8), &attrs_sensors_sens_gyro_device);
  if ( (v7 & 0x80000000) != 0 )
  {
    v9 = v7;
    printk(&unk_766D, "NUBIA_SENSORS_SENS", "sensors_sensitivity_register", 389);
    v10 = *(_QWORD *)(sensors_sens_data + 8);
    device_remove_file(v10, &attrs_sensors_sens_gyro_device);
    device_remove_file(v10, &off_B8);
    device_remove_file(v10, &off_D8);
    device_remove_file(v10, &off_F8);
    goto LABEL_16;
  }
  if ( SENSORS_SENS_LOG_LEVEL >= 2 )
    printk(&unk_72CB, "NUBIA_SENSORS_SENS", "sensors_sensitivity_register", 393);
  return 0;
}
