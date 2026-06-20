__int64 __fastcall qcom_cpucp_v2_mbox_rx_interrupt(__int64 a1, __int64 a2)
{
  unsigned int *v3; // x22
  __int64 v4; // x8
  __int64 v5; // x0
  unsigned int v6; // w8
  __int64 v7; // x20
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x10
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x21
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int **)(a2 + 152);
  v4 = *(_QWORD *)(a2 + 168);
  v17[0] = 0;
  v5 = readq(v4 + v3[4]);
  v6 = v3[8];
  if ( v6 )
  {
    v7 = v5;
    v8 = 0;
    result = 0;
    while ( 1 )
    {
      v10 = *(unsigned int *)(a2 + 188);
      if ( (_DWORD)v10 )
      {
        if ( ((1LL << v8) & v10) != 0 && ((1LL << v8) & v7) != 0 )
        {
LABEL_10:
          v11 = readq(*(_QWORD *)(a2 + 168) + v3[2] + v3[6] * v8);
          v12 = *(_QWORD *)(a2 + 168);
          v13 = v3[5];
          v17[0] = v11;
          writeq(v7, (_QWORD *)(v12 + v13));
          __dsb(0xFu);
          v14 = raw_spin_lock_irqsave(*(_QWORD *)(a2 + 144) + 4LL * v8);
          v15 = *(_QWORD *)(a2 + 136);
          v16 = v14;
          if ( *(_QWORD *)(v15 + 248LL * v8 + 240) <= 0xFFFFFFFFFFFFF000LL )
            mbox_chan_received_data(v15 + 248LL * v8, v17);
          raw_spin_unlock_irqrestore(*(_QWORD *)(a2 + 144) + 4LL * v8, v16);
          v6 = v3[8];
          result = 1;
        }
      }
      else if ( ((1LL << v8) & v7) != 0 )
      {
        goto LABEL_10;
      }
      if ( ++v8 >= v6 )
        goto LABEL_13;
    }
  }
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
