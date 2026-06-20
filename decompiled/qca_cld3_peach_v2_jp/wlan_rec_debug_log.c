void *__fastcall wlan_rec_debug_log(
        void *result,
        char a2,
        unsigned __int8 a3,
        __int16 a4,
        const void *a5,
        __int64 a6,
        int a7,
        int a8)
{
  unsigned __int64 StatusReg; // x9
  int v13; // w11
  unsigned int v14; // w10
  unsigned __int64 v15; // x22
  unsigned __int64 v16; // x24
  char *v17; // x23
  void *v18; // x0
  unsigned int v20; // w10
  signed int v21; // w10
  unsigned int v27; // w12

  if ( (unsigned int)result <= 1 )
  {
    LODWORD(StatusReg) = 5136;
    _X8 = (unsigned int *)((char *)&global_wlan_roam_debug_table + 5136 * (unsigned int)result);
    if ( _X8 )
    {
      while ( 1 )
      {
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v20 = __ldxr(_X8);
          v21 = v20 + 1;
        }
        while ( __stlxr(v21, _X8) );
        __dmb(0xBu);
        if ( v21 == 128 )
        {
          __asm { PRFM            #0x11, [X8] }
          do
            v27 = __ldxr(_X8);
          while ( __stxr(v27 - 128, _X8) );
        }
        v13 = v21 <= 127 ? 127 : v21;
        v14 = v21 - (v13 & 0x7FFFFF80);
        if ( v14 < 0x81 )
          break;
LABEL_22:
        __break(0x5512u);
      }
      v15 = (unsigned int)result * (unsigned __int64)(unsigned int)StatusReg + 40LL * v14 + 16;
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      if ( v15 >> 5 <= 0x140 )
      {
        _X8 += 10 * v14;
        v16 = v15 >> 3;
        v17 = (char *)(_X8 + 4);
        *((_QWORD *)_X8 + 2) = StatusReg;
        if ( v15 >> 3 <= 0x502 )
        {
          _X8 = (unsigned int *)&dword_2814;
          LODWORD(StatusReg) = a3;
          *((_DWORD *)v17 + 2) = a3;
          if ( v15 <= 0x2814 )
          {
            _X8 = (unsigned int *)(&dword_2810 + 2);
            v17[12] = a2;
            if ( v15 <= 0x2812 )
            {
              v18 = v17 + 16;
              *((_WORD *)v17 + 7) = a4;
              if ( a5 )
              {
                result = qdf_mem_copy(v18, a5, 6u);
                if ( v16 > 0x500 )
                  goto LABEL_21;
LABEL_17:
                _X8 = (unsigned int *)(v15 >> 11);
                *((_QWORD *)v17 + 3) = a6;
                if ( v15 >> 11 <= 4 )
                {
                  _X8 = (unsigned int *)&dword_27FC;
                  *((_DWORD *)v17 + 8) = a7;
                  if ( v15 <= 0x27FC )
                  {
                    *((_DWORD *)v17 + 9) = a8;
                    return result;
                  }
                }
                goto LABEL_21;
              }
              result = qdf_mem_set(v18, 6u, 0);
              if ( v16 <= 0x500 )
                goto LABEL_17;
            }
          }
        }
      }
LABEL_21:
      __break(1u);
      goto LABEL_22;
    }
  }
  return result;
}
