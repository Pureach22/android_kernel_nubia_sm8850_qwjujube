__int64 __fastcall adreno_hwsched_parse_fault_cmdobj(__int64 result, __int64 a2)
{
  _QWORD *v2; // x22
  __int64 v3; // x19
  _QWORD *v4; // x21
  unsigned __int64 v12; // x9
  __int64 v13; // x24
  _QWORD *v14; // x25
  _QWORD *v15; // x26
  __int64 v16; // x3
  __int64 v17; // x4

  if ( (*(_BYTE *)(result + 11304) & 1) == 0 )
  {
    v2 = *(_QWORD **)(result + 22768);
    v3 = result;
    v4 = (_QWORD *)(result + 22768);
    while ( v2 != v4 )
    {
      v13 = *(v2 - 1);
      v2 = (_QWORD *)*v2;
      if ( (*(_BYTE *)(v13 + 16) & 1) != 0 && (*(_QWORD *)(v13 + 56) & 0x10) != 0 )
      {
        v14 = (_QWORD *)(v13 + 88);
        v15 = *(_QWORD **)(v13 + 88);
        if ( v15 != (_QWORD *)(v13 + 88) )
        {
          do
          {
            while ( 1 )
            {
              v16 = v15[4];
              v17 = v15[5] >> 2;
              if ( (*(_BYTE *)(*(_QWORD *)(v13 + 8) + 203LL) & 0x20) == 0 )
                break;
              result = adreno_parse_ib_lpac(v3, a2, *(_QWORD *)(a2 + 232), v16, v17);
              v15 = (_QWORD *)*v15;
              if ( v15 == v14 )
                goto LABEL_4;
            }
            result = adreno_parse_ib(v3, a2, *(_QWORD *)(a2 + 224), v16, v17);
            v15 = (_QWORD *)*v15;
          }
          while ( v15 != v14 );
        }
LABEL_4:
        _X8 = (unsigned __int64 *)(v13 + 56);
        __asm { PRFM            #0x11, [X8] }
        do
          v12 = __ldxr(_X8);
        while ( __stxr(v12 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
      }
    }
  }
  return result;
}
