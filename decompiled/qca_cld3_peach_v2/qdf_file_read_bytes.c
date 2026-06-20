__int64 __fastcall qdf_file_read_bytes(const char *a1, __int64 *a2, _DWORD *a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a2 = 0;
  v10[0] = 0;
  if ( (unsigned int)firmware_request_nowarn(v10, a1, 0) )
  {
    qdf_trace_msg(56, 2, "%s: Failed to read file %s", "qdf_file_read_bytes", a1);
    result = 16;
  }
  else
  {
    v7 = _qdf_mem_malloc(*(_QWORD *)v10[0], "qdf_file_read_bytes", 144);
    if ( v7 )
    {
      v8 = v7;
      qdf_mem_copy(v7, *(__int64 *)((char *)&qword_8 + v10[0]), *(unsigned int *)v10[0]);
      v9 = v10[0];
      *a3 = *(_QWORD *)v10[0];
      *a2 = v8;
      release_firmware(v9);
      result = 0;
    }
    else
    {
      release_firmware(v10[0]);
      result = 2;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
