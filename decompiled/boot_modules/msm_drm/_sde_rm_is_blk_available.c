__int64 __fastcall sde_rm_is_blk_available(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  int v7; // w10
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 result; // x0
  __int64 *v11; // x22

  v4 = *(_QWORD *)(a2 + 16);
  if ( *(_BYTE *)(a4 + 116) != 1 )
    goto LABEL_6;
  if ( v4 && (v7 = *(_DWORD *)(a3 + 20), *(_DWORD *)(v4 + 20) != v7) )
  {
    v8 = *(_QWORD *)(a2 + 24);
    if ( !v8 )
      goto LABEL_14;
  }
  else
  {
    v8 = *(_QWORD *)(a2 + 24);
    if ( !v8 || (v7 = *(_DWORD *)(a3 + 20), *(_DWORD *)(v8 + 20) == v7) )
    {
LABEL_6:
      if ( !v4 || *(_DWORD *)(v4 + 20) == *(_DWORD *)(a3 + 20) )
      {
        v9 = *(_QWORD *)(a2 + 24);
        if ( !v9 || *(_DWORD *)(v9 + 20) == *(_DWORD *)(a3 + 20) )
          return 1;
      }
      return 0;
    }
  }
  result = 0;
  if ( v4 && *(_DWORD *)(v8 + 20) == v7 )
  {
LABEL_14:
    v11 = *(__int64 **)(*(_QWORD *)a1 + 816LL);
    if ( v11 != (__int64 *)(*(_QWORD *)a1 + 816LL) )
    {
      while ( *((_DWORD *)v11 + 4) != *(_DWORD *)(*(_QWORD *)(a2 + 16) + 20LL)
           || !sde_encoder_is_dsi_display((_BOOL8)(v11 - 1))
           && (v11 == (__int64 *)&unk_8 || (*((_BYTE *)v11 + 636) & 0x80) == 0) )
      {
        v11 = (__int64 *)*v11;
        if ( v11 == (__int64 *)(*(_QWORD *)a1 + 816LL) )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  return result;
}
