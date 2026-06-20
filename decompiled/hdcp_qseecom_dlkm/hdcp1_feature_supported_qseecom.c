__int64 __fastcall hdcp1_feature_supported_qseecom(__int64 *a1)
{
  int v3; // w24
  __int64 v4; // x0
  __int64 v5; // x28
  int v6; // w1
  void *v7; // x0
  unsigned int v8; // w20

  if ( !a1 )
  {
    printk(&unk_C81E);
    return 0;
  }
  if ( (a1[2] & 1) != 0 )
    return 1;
  if ( (unsigned int)hdcp1_app_load(a1) || (a1[3] & 1) == 0 )
    return 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = *a1;
    if ( *a1 )
    {
      if ( (a1[3] & 1) != 0 )
      {
        **(_DWORD **)(v4 + 8) = 204;
        v5 = *(_QWORD *)(v4 + 8);
        if ( (qseecom_send_command() & 0x80000000) != 0 )
        {
          v7 = &unk_C9F5;
        }
        else
        {
          v6 = *(_DWORD *)(v5 + 68);
          qseecomd_down = v6 == -4103;
          if ( !v6 )
          {
            v8 = 1;
            *((_BYTE *)a1 + 16) = 1;
            goto LABEL_20;
          }
          v7 = &unk_C801;
        }
        printk(v7);
      }
      else
      {
        printk(&unk_C830);
      }
    }
    else
    {
      printk(&unk_C470);
    }
    if ( qseecomd_down != 1 )
      break;
    msleep(100);
    if ( *((_DWORD *)a1 + 10) < (unsigned int)++v3 )
    {
      if ( (qseecomd_down & 1) != 0 )
        printk(&unk_C5F7);
      break;
    }
  }
  v8 = 0;
LABEL_20:
  hdcp1_app_unload(a1);
  return v8;
}
