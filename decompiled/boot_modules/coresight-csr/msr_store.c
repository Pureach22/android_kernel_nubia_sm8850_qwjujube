__int64 __fastcall msr_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v4; // x8
  __int64 result; // x0
  unsigned __int64 v6; // x19
  unsigned __int64 v7; // x8
  __int64 v9; // x0
  __int64 v10; // x11
  unsigned int v17; // w9
  __int64 v18; // [xsp+0h] [xbp-10h] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  result = -22;
  v6 = *(_QWORD *)(v4 + 152);
  if ( v6 )
  {
    if ( v6 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(v6 + 162) == 1 )
    {
      v7 = *(_QWORD *)(v6 + 48);
      if ( v7 )
      {
        if ( v7 <= 0xFFFFFFFFFFFFF000LL )
        {
          v18 = 0;
          if ( sscanf(s, "%x %x", (char *)&v18 + 4, &v18) == 2
            && HIDWORD(v18) < (unsigned __int64)(*(_QWORD *)(v6 + 24) - *(_QWORD *)(v6 + 16) + 1LL) >> 2 )
          {
            if ( !**(_DWORD **)(v6 + 56) )
            {
              LODWORD(result) = clk_prepare_enable(*(_QWORD *)(v6 + 144));
              if ( (_DWORD)result )
              {
                result = (int)result;
                goto LABEL_11;
              }
              _X8 = *(unsigned int **)(v6 + 56);
              __asm { PRFM            #0x11, [X8] }
              do
                v17 = __ldxr(_X8);
              while ( __stxr(v17 + 1, _X8) );
            }
            v9 = raw_spin_lock_irqsave(v6 + 152);
            *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = -978530731;
            __dsb(0xFu);
            v10 = *(_QWORD *)v6 + *(_QWORD *)(v6 + 16);
            LODWORD(v18) = v18 | *(_DWORD *)(v10 + (unsigned int)(4 * HIDWORD(v18)));
            *(_DWORD *)(v10 + (unsigned int)(4 * HIDWORD(v18))) = v18;
            *(_DWORD *)(*(_QWORD *)(v6 + 48) + 4LL * HIDWORD(v18)) = *(_DWORD *)(*(_QWORD *)v6
                                                                               + *(_QWORD *)(v6 + 16)
                                                                               + (unsigned int)(4 * HIDWORD(v18)));
            __dsb(0xFu);
            *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = 0;
            raw_spin_unlock_irqrestore(v6 + 152, v9);
            result = a4;
          }
          else
          {
            result = -22;
          }
        }
      }
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
