__int64 __fastcall qmi_ts_ind_cb_v02(__int64 result, int a2, __int64 a3, char *s2)
{
  char v5; // w21
  __int64 *v6; // x22
  const char *v7; // x20
  __int64 v8; // x9
  int v9; // w8
  char v10; // w9
  void *v11; // x0

  if ( !a3 )
  {
    v11 = &unk_83AF;
    return printk(v11, "qti_qmi_sensor_v2", "qmi_ts_ind_cb_v02");
  }
  if ( *((_DWORD *)s2 + 9) || s2[48] )
  {
    v5 = 0;
    if ( s2[40] )
      goto LABEL_5;
    goto LABEL_16;
  }
  v5 = 1;
  if ( !s2[40] )
  {
LABEL_16:
    v11 = &unk_82FE;
    return printk(v11, "qti_qmi_sensor_v2", "qmi_ts_ind_cb_v02");
  }
LABEL_5:
  v6 = (__int64 *)(result + 360);
  v7 = (const char *)(result + 360);
  while ( 1 )
  {
    v7 = *(const char **)v7;
    if ( v7 == (const char *)v6 )
      break;
    result = strncasecmp(v7 - 48, s2, 0x20u);
    if ( !(_DWORD)result )
    {
      v8 = *((_QWORD *)v7 + 2);
      v9 = *((_DWORD *)s2 + 11);
      *((_DWORD *)v7 + 6) = v9;
      if ( v8 )
        v10 = v5;
      else
        v10 = 1;
      if ( (v10 & 1) == 0 && (v9 >= *((_DWORD *)v7 + 7) || v9 <= *((_DWORD *)v7 + 8)) )
        return queue_work_on(32, system_highpri_wq, v7 + 56);
      return result;
    }
  }
  return result;
}
