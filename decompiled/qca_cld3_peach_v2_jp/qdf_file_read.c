__int64 __fastcall qdf_file_read(const char *a1, __int64 *a2, _DWORD *a3)
{
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v8; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a2 = 0;
  v9[0] = 0;
  if ( (unsigned int)firmware_request_nowarn(v9, a1, 0) )
  {
    qdf_trace_msg(56, 2, "%s: Failed to read file %s", "qdf_file_read", a1);
    result = 16;
  }
  else
  {
    v7 = _qdf_mem_malloc(*(_QWORD *)v9[0] + 1LL, "qdf_file_read", 63);
    if ( v7 )
    {
      qdf_mem_copy(v7, *(__int64 *)((char *)&qword_8 + v9[0]), *(unsigned int *)v9[0]);
      v8 = v9[0];
      if ( a3 )
        *a3 = *(_DWORD *)v9[0] + 1;
      release_firmware(v8);
      result = 0;
      *a2 = v7;
    }
    else
    {
      release_firmware(v9[0]);
      result = 2;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
