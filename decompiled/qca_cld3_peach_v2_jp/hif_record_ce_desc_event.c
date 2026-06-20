__int64 __usercall hif_record_ce_desc_event@<X0>(
        __int64 result@<X0>,
        int a2@<W1>,
        int a3@<W2>,
        __int64 a4@<X3>,
        __int64 a5@<X4>,
        int a6@<W5>,
        __int64 a7@<X8>)
{
  int v8; // w20
  __int64 v9; // x21
  unsigned int v14; // w10
  signed int v15; // w9
  __int64 v16; // x22
  __int64 v17; // x0
  unsigned __int64 StatusReg; // x9
  int v19; // w8
  __int64 v20; // x10
  __int64 v21; // x3
  unsigned int v23; // w9
  signed int v24; // w9
  unsigned int v30; // w12
  int v31; // [xsp+1Ch] [xbp+1Ch]

  if ( a2 <= 11 )
  {
    if ( (unsigned int)a2 >= 0xC )
    {
      __break(0x5512u);
      goto LABEL_20;
    }
    if ( *(_BYTE *)(result + a2 + 2812) == 1 )
    {
      a7 = *(_QWORD *)(result + 8LL * a2 + 3616);
      if ( a7 )
      {
        v9 = result + 2752;
        v8 = a3;
        _X10 = (unsigned int *)(result + 2752 + 4LL * a2);
LABEL_20:
        __asm { PRFM            #0x11, [X10] }
        do
        {
          v23 = __ldxr(_X10);
          v24 = v23 + 1;
        }
        while ( __stlxr(v24, _X10) );
        __dmb(0xBu);
        if ( v24 == 768 )
        {
          __asm { PRFM            #0x11, [X10] }
          do
            v30 = __ldxr(_X10);
          while ( __stxr(v30 - 768, _X10) );
        }
        if ( v24 <= 767 )
          v14 = 767;
        else
          v14 = v24;
        v15 = -768 * ((unsigned int)((715827883 * (unsigned __int64)v14) >> 32) >> 7) + v24;
        v16 = a7 + 56LL * v15;
        v17 = qdf_mem_set((int)a7 + 56 * v15, 0x38u, 0);
        *(_DWORD *)(v16 + 4) = v8;
        __isb(0xFu);
        *(_QWORD *)(v16 + 8) = _ReadStatusReg(CNTVCT_EL0);
        StatusReg = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(StatusReg + 16);
        v19 = *(_DWORD *)(StatusReg + 40);
        v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v20;
        if ( v20 && *(_QWORD *)(StatusReg + 16) )
        {
          *(_DWORD *)(v16 + 16) = v19;
          if ( !a4 )
          {
LABEL_15:
            v21 = *(_QWORD *)(v16 + 8);
            *(_QWORD *)(v16 + 48) = a5;
            *(_DWORD *)v16 = a6;
            return hif_record_latest_evt(v9, v8, a2, v21, 0, 0);
          }
        }
        else
        {
          v31 = v19;
          preempt_schedule(v17);
          *(_DWORD *)(v16 + 16) = v31;
          if ( !a4 )
            goto LABEL_15;
        }
        qdf_mem_copy(v16 + 28, a4, 8u);
        goto LABEL_15;
      }
    }
  }
  return result;
}
