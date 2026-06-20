__int64 __fastcall aw9620x_i2c_remove(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 184);
  input_unregister_device(*(_QWORD *)(*(_QWORD *)(v1 + 512) + 8LL));
  v3 = *(_QWORD *)(v1 + 512);
  if ( *(_QWORD *)(v3 + 8) )
  {
    input_free_device();
    v3 = *(_QWORD *)(v1 + 512);
  }
  input_unregister_device(*(_QWORD *)(v3 + 56));
  v4 = *(_QWORD *)(v1 + 512);
  if ( *(_QWORD *)(v4 + 56) )
  {
    input_free_device();
    v4 = *(_QWORD *)(v1 + 512);
  }
  input_unregister_device(*(_QWORD *)(v4 + 104));
  v5 = *(_QWORD *)(v1 + 512);
  if ( *(_QWORD *)(v5 + 104) )
  {
    input_free_device();
    v5 = *(_QWORD *)(v1 + 512);
  }
  input_unregister_device(*(_QWORD *)(v5 + 152));
  v6 = *(_QWORD *)(v1 + 512);
  if ( *(_QWORD *)(v6 + 152) )
  {
    input_free_device();
    v6 = *(_QWORD *)(v1 + 512);
  }
  input_unregister_device(*(_QWORD *)(v6 + 200));
  v7 = *(_QWORD *)(v1 + 512);
  if ( *(_QWORD *)(v7 + 200) )
  {
    input_free_device();
    v7 = *(_QWORD *)(v1 + 512);
  }
  input_unregister_device(*(_QWORD *)(v7 + 248));
  v8 = *(_QWORD *)(v1 + 512);
  if ( *(_QWORD *)(v8 + 248) )
  {
    input_free_device();
    v8 = *(_QWORD *)(v1 + 512);
  }
  input_unregister_device(*(_QWORD *)(v8 + 296));
  v9 = *(_QWORD *)(v1 + 512);
  if ( *(_QWORD *)(v9 + 296) )
  {
    input_free_device();
    v9 = *(_QWORD *)(v1 + 512);
  }
  input_unregister_device(*(_QWORD *)(v9 + 344));
  if ( *(_QWORD *)(*(_QWORD *)(v1 + 512) + 344LL) )
    input_free_device();
  result = sysfs_remove_group(a1 + 32, &aw9620x_touch_attribute_group);
  if ( *(_BYTE *)(v1 + 1) )
  {
    regulator_disable(*(_QWORD *)(v1 + 504));
    return regulator_put(*(_QWORD *)(v1 + 504));
  }
  return result;
}
