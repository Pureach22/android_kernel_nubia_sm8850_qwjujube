__int64 __fastcall accel_enable_show(__int64 a1, int a2, char *s)
{
  __int64 v3; // x19
  char *v4; // x0

  v3 = *(_QWORD *)(a1 + 152);
  v4 = s;
  if ( SENSORS_SENS_LOG_LEVEL >= 2 )
  {
    printk(&unk_72FC, "NUBIA_SENSORS_SENS", "accel_enable_show", 105);
    v4 = s;
  }
  return sprintf(v4, "%d\n", *(unsigned __int8 *)(v3 + 64));
}
