__int64 __fastcall _qdf_nbuf_remove_frag(__int64 result, unsigned __int16 a2, unsigned __int16 a3)
{
  int v3; // w19
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 v7; // x9
  __int64 v8; // x20
  unsigned __int16 v9; // w21
  __int64 v10; // x11
  __int64 v11; // x12
  int v12; // w10
  int v13; // w9
  unsigned int v19; // w9
  unsigned int v20; // w9

  v4 = a2;
  if ( a2 >= 0x12u )
  {
    __break(0x5512u);
    goto LABEL_16;
  }
  v5 = *(_QWORD *)(result + 216) + *(unsigned int *)(result + 212) + 88LL;
  v4 = *(_QWORD *)(v5 + 16LL * a2);
  if ( v4 )
    _ZF = (*(_QWORD *)(v5 + 16LL * a2) & 1LL) == 0;
  else
    _ZF = 0;
  if ( _ZF )
  {
    if ( (unsigned __int8)a2 > 0x10u )
    {
      v3 = 0;
      v7 = *(_QWORD *)(v4 + 8);
      if ( (v7 & 1) == 0 )
      {
LABEL_16:
        _X10 = (unsigned int *)(v4 + 52);
        __asm { PRFM            #0x11, [X10] }
        do
        {
          v19 = __ldxr(_X10);
          v20 = v19 - 1;
        }
        while ( __stlxr(v20, _X10) );
        __dmb(0xBu);
        if ( !v20 )
        {
          v8 = result;
          v9 = a3;
          _folio_put(v4);
          result = v8;
          a3 = v9;
        }
        v10 = *(_QWORD *)(result + 216);
        v11 = *(unsigned int *)(result + 212);
        v12 = *(_DWORD *)(result + 232) - a3;
        v13 = *(_DWORD *)(result + 116) - v3;
        *(_DWORD *)(result + 112) -= v3;
        *(_DWORD *)(result + 116) = v13;
        *(_DWORD *)(result + 232) = v12;
        --*(_BYTE *)(v10 + v11 + 2);
        return result;
      }
    }
    else
    {
      v3 = *(unsigned __int16 *)(v5 + 16LL * a2 + 8);
      v7 = *(_QWORD *)(v4 + 8);
      if ( (v7 & 1) == 0 )
        goto LABEL_16;
    }
    v4 = v7 - 1;
    goto LABEL_16;
  }
  return result;
}
