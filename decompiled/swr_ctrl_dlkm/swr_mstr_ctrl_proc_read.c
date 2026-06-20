unsigned __int64 __fastcall swr_mstr_ctrl_proc_read(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  unsigned __int64 v4; // x23
  __int64 v6; // x21
  __int64 v7; // x22
  unsigned __int64 v9; // x27
  unsigned __int64 v10; // x26
  unsigned __int64 StatusReg; // x24
  bool v12; // cc
  int v13; // w0
  unsigned int v14; // w0
  __int64 v15; // x25
  unsigned __int64 v16; // x27
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9
  _QWORD v29[5]; // [xsp+8h] [xbp-28h] BYREF

  v4 = -22;
  v29[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 )
    {
      if ( a3 )
      {
        if ( a4 )
        {
          v6 = *a4;
          if ( (*a4 & 0x8000000000000000LL) == 0 )
          {
            v7 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
            if ( v7 )
            {
              if ( (int)v6 <= 24744 )
              {
                v9 = 0;
                v10 = a3 - 1;
                StatusReg = _ReadStatusReg(SP_EL0);
                memset(v29, 0, 32);
                while ( 1 )
                {
                  if ( (unsigned int)(v6 - 11349) < 0x13AB )
                  {
                    v4 = v9;
                  }
                  else
                  {
                    usleep_range_state(100, 150, 2);
                    v13 = swr_master_read(v7, v6);
                    v14 = scnprintf(v29, 25, "0x%.3x: 0x%.2x\n", v6, v13);
                    if ( (v14 & 0x80000000) != 0 )
                      goto LABEL_24;
                    v15 = v14;
                    v4 = v9 + v14;
                    if ( v4 >= v10 )
                    {
                      v4 = v9;
                      goto LABEL_26;
                    }
                    if ( v14 >= 0x21 )
                    {
                      _copy_overflow(32, v14);
                      v4 = -14;
                      goto LABEL_26;
                    }
                    v16 = a2 + v9;
                    _check_object_size(v29, v14, 1);
                    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0
                      || (v17 = v16, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
                    {
                      v17 = v16 & ((__int64)(v16 << 8) >> 8);
                    }
                    if ( 0x8000000000LL - v15 >= v17 )
                    {
                      v18 = _ReadStatusReg(DAIF);
                      __asm { MSR             DAIFSet, #3 }
                      v24 = *(_QWORD *)(StatusReg + 8);
                      _WriteStatusReg(
                        TTBR1_EL1,
                        v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                      _WriteStatusReg(TTBR0_EL1, v24);
                      __isb(0xFu);
                      _WriteStatusReg(DAIF, v18);
                      v15 = _arch_copy_to_user(v16 & 0xFF7FFFFFFFFFFFFFLL, v29, v15);
                      v25 = _ReadStatusReg(DAIF);
                      __asm { MSR             DAIFSet, #3 }
                      v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                      _WriteStatusReg(TTBR0_EL1, v27 - 4096);
                      _WriteStatusReg(TTBR1_EL1, v27);
                      __isb(0xFu);
                      _WriteStatusReg(DAIF, v25);
                    }
                    if ( v15 )
                    {
LABEL_24:
                      v4 = -14;
                      goto LABEL_26;
                    }
                    v9 = v4;
                    *a4 += 4;
                  }
                  v12 = (int)v6 < 24741;
                  LODWORD(v6) = v6 + 4;
                  if ( !v12 )
                    goto LABEL_26;
                }
              }
              v4 = 0;
            }
          }
        }
      }
    }
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v4;
}
