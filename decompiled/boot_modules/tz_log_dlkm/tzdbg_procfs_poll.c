__int64 __fastcall tzdbg_procfs_poll(__int64 a1)
{
  int v1; // w20
  _UNKNOWN **v3; // x21
  __int64 v4; // x2
  char v5; // w8
  char v6; // w9
  _BOOL4 v7; // w19
  __int64 *v8; // x22
  __int64 *v9; // x8
  int v10; // w20
  __int64 v12; // x8

  v1 = **(_DWORD **)(*(_QWORD *)(a1 + 32) + 128LL);
  if ( (unsigned int)(v1 - 5) > 1 || (byte_330 & 1) == 0 && byte_331 != 1 )
    return 8;
  mutex_lock(&tzdbg_mutex);
  v3 = &clients_list;
  do
    v3 = (_UNKNOWN **)*v3;
  while ( v3 != &clients_list && *(v3 - 1) != (_UNKNOWN *)a1 );
  mutex_unlock(&tzdbg_mutex);
  if ( byte_330 != 1 )
  {
    if ( v1 == 5 )
    {
      _memcpy_fromio(qword_110, tzdbg, (unsigned int)debug_rw_buf_size);
      v12 = qword_110 + *(unsigned int *)(qword_110 + 28);
      if ( (byte_332 & 1) != 0 )
      {
        if ( *((_DWORD *)v3 + 6) != *(_DWORD *)(v12 - 4) || *((_DWORD *)v3 + 5) != *(_DWORD *)(v12 - 8) )
          return 65;
      }
      else if ( *((unsigned __int16 *)v3 + 9) != *(unsigned __int16 *)(v12 - 2)
             || *((unsigned __int16 *)v3 + 8) != *(unsigned __int16 *)(v12 - 4) )
      {
        return 65;
      }
    }
    else if ( byte_331 == 1 )
    {
      if ( (byte_332 & 1) != 0 )
      {
        if ( *((_DWORD *)v3 + 6) != *(_DWORD *)(g_qsee_log_v2 + 4) || *((_DWORD *)v3 + 5) != *(_DWORD *)g_qsee_log_v2 )
          return 65;
      }
      else if ( *((unsigned __int16 *)v3 + 9) != *(unsigned __int16 *)(g_qsee_log + 2)
             || *((unsigned __int16 *)v3 + 8) != *(unsigned __int16 *)g_qsee_log )
      {
        return 65;
      }
    }
    return 0;
  }
  v5 = byte_333;
  v6 = byte_333 & byte_334;
  if ( (byte_333 & 1) == 0 && (byte_334 & 1) != 0 )
  {
    printk(&unk_992A, "is_log_ready", v4);
    v5 = byte_333;
    v6 = byte_334;
  }
  v7 = v1 != 5;
  if ( v1 == 5 )
    v8 = &enc_tzlog_info;
  else
    v8 = &enc_qseelog_info;
  if ( (unsigned int)qcom_scm_request_encrypted_log(*v8, v8[2], v1 != 5, v5 & 1, v6 & 1) )
    return 0;
  v9 = &qword_ABC0;
  if ( v1 == 5 )
    v9 = &qword_ABE0;
  v10 = *(_DWORD *)(*v9 + 8);
  qcom_scm_request_encrypted_log(*v8, v8[2], v7, (unsigned __int8)byte_333, (unsigned __int8)byte_334);
  if ( !v10 )
    return 0;
  return 65;
}
