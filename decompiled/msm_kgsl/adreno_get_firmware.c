__int64 __fastcall adreno_get_firmware(_QWORD *a1, const char *a2, __int64 a3)
{
  unsigned __int64 v4; // x8
  __int64 result; // x0
  int v8; // w0
  unsigned __int64 global; // x8
  _QWORD *v10; // x0
  unsigned int v11; // w9
  unsigned int v12; // w20
  __int64 v13; // x9
  unsigned int v14; // w8
  unsigned int v15; // w19
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a3 + 24);
  v16[0] = 0;
  if ( v4 && v4 < 0xFFFFFFFFFFFFF001LL )
  {
    result = 0;
  }
  else
  {
    v8 = request_firmware(v16, a2, a1[1396] + 16LL);
    if ( v8 )
    {
      v15 = v8;
      dev_err(*a1, "request_firmware(%s) failed: %d\n", a2, v8);
      result = v15;
    }
    else
    {
      global = kgsl_allocate_global(a1, *(_QWORD *)v16[0] - 4LL, 0, 0x1000000, 128, "ucode");
      v10 = (_QWORD *)v16[0];
      *(_QWORD *)(a3 + 24) = global;
      if ( global <= 0xFFFFFFFFFFFFF000LL )
        v11 = 0;
      else
        v11 = global;
      v12 = v11;
      if ( !v11 )
      {
        memcpy(*(void **)(*(_QWORD *)(a3 + 24) + 8LL), (const void *)(*(_QWORD *)(v16[0] + 8LL) + 4LL), *v10 - 4LL);
        v10 = (_QWORD *)v16[0];
        *(_QWORD *)(a3 + 8) = (unsigned __int64)(*(_QWORD *)v16[0] - 4LL) >> 2;
        v13 = v10[1];
        v14 = *(_DWORD *)(v13 + 4);
        if ( (v14 & 0xF) == 0xA )
          v14 = v14 & 0xFFFFF000 | (*(_DWORD *)(v13 + 12) >> 12) & 0xFFF;
        *(_DWORD *)(a3 + 16) = v14;
      }
      release_firmware(v10);
      result = v12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
