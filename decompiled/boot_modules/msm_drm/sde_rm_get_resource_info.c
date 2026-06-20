__int64 __fastcall sde_rm_get_resource_info(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x11
  bool is_built_in_display; // w22
  __int64 v10; // x24
  __int64 **v11; // x28
  __int64 *v12; // x23
  __int64 v13; // x8
  __int64 v14; // x8
  int v15; // w9
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // x8
  unsigned __int64 v25; // x10

  mutex_lock(a1 + 35);
  *(_QWORD *)a3 = a1[42];
  v6 = a1[46];
  v7 = a1[43];
  v8 = a1[44];
  *(_QWORD *)(a3 + 24) = a1[45];
  *(_QWORD *)(a3 + 32) = v6;
  *(_QWORD *)(a3 + 8) = v7;
  *(_QWORD *)(a3 + 16) = v8;
  if ( a2 )
    is_built_in_display = sde_encoder_is_built_in_display(a2);
  else
    is_built_in_display = 0;
  v10 = 0;
  while ( 2 )
  {
    v11 = (__int64 **)&a1[2 * v10 + 3];
    v12 = *v11;
    while ( v12 != (__int64 *)v11 )
    {
      v13 = v12[2];
      if ( a2 && v13 && *(_DWORD *)(v13 + 20) == *(_DWORD *)(a2 + 24) )
      {
        sde_rm_inc_resource_info(a1, a3, v12);
        if ( v10 != 2 )
          goto LABEL_8;
        ++*(_DWORD *)a3;
        v13 = v12[2];
      }
      else if ( v10 != 2 )
      {
        goto LABEL_8;
      }
      if ( v13
        || v12[3] != 0
        || is_built_in_display
        || (v14 = *(_QWORD *)(v12[5] + 40), (*(_QWORD *)(v14 + 32) & 0x60LL) == 0) )
      {
LABEL_8:
        v12 = (__int64 *)*v12;
      }
      else
      {
        v15 = *((_DWORD *)v12 + 8);
        if ( v15 > 9 )
        {
          if ( v15 == 10 )
          {
            --*(_DWORD *)(a3 + 8);
            goto LABEL_8;
          }
          if ( v15 != 11 )
            goto LABEL_8;
          --*(_DWORD *)(a3 + 12);
          v12 = (__int64 *)*v12;
        }
        else if ( v15 == 2 )
        {
          if ( (*(_BYTE *)(v14 + 72) & 1) != 0 )
            goto LABEL_8;
          --*(_DWORD *)(a3 + 4);
          v16 = *(unsigned int *)(v14 + 68);
          v17 = v16 >> 6;
          v18 = 1LL << v16;
          _X9 = (unsigned __int64 *)(a3 + 32 + 8 * v17);
          __asm { PRFM            #0x11, [X9] }
          do
            v25 = __ldxr(_X9);
          while ( __stxr(v25 & ~v18, _X9) );
          *(_DWORD *)(a3 + 20) = _sw_hweight64(*(_QWORD *)(a3 + 32));
          v12 = (__int64 *)*v12;
        }
        else
        {
          if ( v15 != 5 )
            goto LABEL_8;
          --*(_DWORD *)(a3 + 16);
          v12 = (__int64 *)*v12;
        }
      }
    }
    if ( ++v10 != 15 )
      continue;
    return mutex_unlock(a1 + 35);
  }
}
