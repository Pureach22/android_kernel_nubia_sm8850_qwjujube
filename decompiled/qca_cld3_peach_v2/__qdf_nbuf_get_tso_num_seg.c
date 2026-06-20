__int64 __fastcall _qdf_nbuf_get_tso_num_seg(__int64 a1)
{
  __int64 v1; // x11
  __int64 v2; // x8
  __int64 v3; // x12
  __int64 v4; // x9
  __int64 v5; // x4
  int v6; // w13
  unsigned int v7; // w8
  unsigned int v8; // w13
  unsigned int v9; // w10
  __int64 result; // x0
  __int64 v12; // x16
  char v13; // w14
  __int64 v14; // x11
  char v15; // w13
  unsigned int v16; // w16
  bool v17; // zf
  int v18; // w1
  int v19; // w16
  __int64 v20; // x15
  unsigned int v21; // w10
  int v22; // w16

  v1 = *(_QWORD *)(a1 + 216);
  v2 = *(unsigned __int16 *)(a1 + 182);
  v3 = *(unsigned int *)(a1 + 212);
  v4 = v1 + v2;
  v5 = *(unsigned __int8 *)(v1 + v3 + 2);
  v6 = *(_DWORD *)(a1 + 112) + *(unsigned __int16 *)(a1 + 186) - (_DWORD)v2;
  v7 = *(unsigned __int16 *)(v1 + v3 + 4);
  LODWORD(v4) = v6 - *(_DWORD *)(a1 + 116) - ((*(unsigned __int16 *)(v4 + 12) >> 2) & 0x3C);
  v8 = (unsigned int)v4 / v7;
  v9 = (unsigned int)v4 % v7;
  if ( (unsigned int)v4 % v7 )
    _ZF = v5 == 0;
  else
    _ZF = 0;
  if ( _ZF )
    result = v8 + 1;
  else
    result = v8;
  if ( *(_BYTE *)(v1 + v3 + 2) )
  {
    v12 = 0;
    v13 = v9 != 0;
    v14 = v3 + v1 + 96;
    v15 = v5;
    while ( 1 )
    {
      if ( 16 * v5 == v12 )
      {
        qdf_trace_msg(56, 4, "%s: TSO: nr_frags %d j %d", "__qdf_nbuf_get_tso_num_seg", v5, v5);
        return 0;
      }
      v20 = v12 + 16;
      if ( v12 == 288 )
        break;
      --v15;
      v21 = *(_DWORD *)(v14 + v12) + v9;
      v22 = v21 / v7;
      v9 = v21 % v7;
      v16 = v22 + result;
      if ( v9 )
      {
        if ( v16 <= (unsigned int)result )
          ++v13;
        else
          v13 = 1;
        if ( v13 == 5 )
        {
          v9 = 0;
          ++v16;
        }
        if ( v15 )
          v17 = 1;
        else
          v17 = v9 == 0;
        v18 = !v17;
        if ( v17 )
          result = v16;
        else
          result = v16 + 1;
        if ( v13 == 5 )
          v19 = 1;
        else
          v19 = v18;
        if ( v19 )
          v13 = 0;
      }
      else
      {
        v13 = 0;
        result = v16;
      }
      v12 = v20;
      if ( !v15 )
        return result;
    }
    __break(0x5512u);
    __asm { PRFM            #0xC, unk_C976C }
    return _qdf_dmaaddr_to_32s(result);
  }
  return result;
}
