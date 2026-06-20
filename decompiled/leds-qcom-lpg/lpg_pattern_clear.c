__int64 __fastcall lpg_pattern_clear(__int64 *a1)
{
  __int64 v2; // x20
  unsigned int v3; // w21
  __int64 v4; // x24
  __int64 v5; // x0
  _QWORD *v6; // x25
  int v7; // w8
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 result; // x0
  _BYTE v12[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  mutex_lock(*a1 + 16);
  if ( *(_DWORD *)(a1[116] + 100) != *(_DWORD *)(a1[116] + 96) )
    _bitmap_clear(*(_QWORD *)(v2 + 88));
  if ( *((_DWORD *)a1 + 230) )
  {
    v3 = 0;
    do
    {
      v4 = a1[(int)v3 + 116];
      v12[0] = 0;
      v5 = *(_QWORD *)(*(_QWORD *)v4 + 104LL);
      if ( v5 )
      {
        nvmem_device_write(v5, *(unsigned int *)(v4 + 24), 1, v12);
        v6 = *(_QWORD **)v4;
        v7 = *(_DWORD *)(v4 + 16);
        v13[0] = 0;
        v8 = v6[13];
        if ( v8 )
        {
          v9 = v6[15] & (unsigned int)~v7;
          v6[15] = v9;
          if ( !v9 && (nvmem_device_write(v8, 66, 1, v13) & 0x80000000) == 0 && v6[14] )
          {
            v10 = v6[13];
            v13[0] = 1;
            nvmem_device_write(v10, 230, 1, v13);
          }
        }
      }
      *(_QWORD *)(v4 + 96) = 0;
      ++v3;
    }
    while ( v3 < *((_DWORD *)a1 + 230) );
  }
  result = mutex_unlock(v2 + 16);
  _ReadStatusReg(SP_EL0);
  return result;
}
