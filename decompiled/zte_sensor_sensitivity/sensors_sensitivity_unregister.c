__int64 sensors_sensitivity_unregister()
{
  __int64 v0; // x19
  __int64 v1; // x19

  v0 = *(_QWORD *)sensors_sens_data;
  device_remove_file(*(_QWORD *)sensors_sens_data, &attrs_sensors_sens_accel_device);
  device_remove_file(v0, &off_38);
  device_remove_file(v0, &off_58);
  device_remove_file(v0, &off_78);
  v1 = *(_QWORD *)(sensors_sens_data + 8);
  device_remove_file(v1, &attrs_sensors_sens_gyro_device);
  device_remove_file(v1, &off_B8);
  device_remove_file(v1, &off_D8);
  device_remove_file(v1, &off_F8);
  return kfree(sensors_sens_data);
}
