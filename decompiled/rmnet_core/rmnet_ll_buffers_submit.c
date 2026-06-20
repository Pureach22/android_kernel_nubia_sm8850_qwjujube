__int64 __fastcall rmnet_ll_buffers_submit(__int64 result, _QWORD *a2)
{
  _QWORD *v2; // x20
  __int64 v4; // x21
  __int64 (__fastcall *v5)(__int64, _QWORD *); // x8
  __int64 v6; // x8
  unsigned int v13; // w8
  unsigned int v14; // w8

  v2 = (_QWORD *)*a2;
  if ( (_QWORD *)*a2 != a2 )
  {
    v4 = result;
    do
    {
      if ( (*((_BYTE *)v2 + 25) & 1) == 0 )
      {
        v5 = (__int64 (__fastcall *)(__int64, _QWORD *))rmnet_ll_client;
        if ( !rmnet_ll_client )
          goto LABEL_10;
        if ( *((_DWORD *)rmnet_ll_client - 1) != -191518848 )
          __break(0x8228u);
        result = v5(v4, v2);
        if ( !(_DWORD)result )
        {
          *((_BYTE *)v2 + 25) = 1;
          ++qword_2FDB0;
        }
        else
        {
LABEL_10:
          ++qword_2FDB8;
          if ( *((_BYTE *)v2 + 24) == 1 )
          {
            result = v2[2];
            v6 = *(_QWORD *)(result + 8);
            if ( (v6 & 1) != 0 )
              result = v6 - 1;
            _X9 = (unsigned int *)(result + 52);
            __asm { PRFM            #0x11, [X9] }
            do
            {
              v13 = __ldxr(_X9);
              v14 = v13 - 1;
            }
            while ( __stlxr(v14, _X9) );
            __dmb(0xBu);
            if ( !v14 )
              result = _folio_put(result);
          }
        }
      }
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != a2 );
  }
  return result;
}
