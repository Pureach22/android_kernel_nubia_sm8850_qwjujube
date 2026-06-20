__int64 __fastcall qpnpint_irq_set_type(__int64 a1, int a2)
{
  unsigned __int64 v2; // x8
  int v4; // w27
  void *v5; // x26
  int v6; // w28
  unsigned int v7; // w24
  int v8; // w9
  __int64 v9; // x23
  __int64 v10; // x21
  unsigned int v11; // w22
  __int64 *v12; // x20
  __int64 v13; // x25
  _DWORD *v14; // x8
  _DWORD *v15; // x8
  unsigned int v16; // w0
  __int64 v17; // x25
  unsigned int v18; // w28
  _DWORD *v19; // x8
  unsigned int v20; // w26
  _DWORD *v21; // x8
  __int64 v22; // x0
  __int64 **v23; // x8
  __int64 *v24; // x25
  unsigned int v25; // w0
  unsigned int v26; // w28
  int v27; // w8
  __int64 v28; // x24
  unsigned int v30; // [xsp+8h] [xbp-28h]
  char v31; // [xsp+Ch] [xbp-24h]
  __int64 v32; // [xsp+10h] [xbp-20h]
  __int64 v33; // [xsp+18h] [xbp-18h]
  int v34; // [xsp+20h] [xbp-10h]
  int v35; // [xsp+24h] [xbp-Ch]
  void *v36; // [xsp+28h] [xbp-8h]

  v2 = *(_QWORD *)(a1 + 8);
  v4 = 1 << (BYTE2(v2) & 7);
  if ( (a2 & 3) != 0 )
  {
    v5 = &handle_edge_irq;
    v6 = 1 << (BYTE2(v2) & 7);
    v34 = (a2 << 31 >> 31) & v4;
    v35 = v4 & (a2 << 30 >> 31);
    goto LABEL_9;
  }
  if ( (~a2 & 0xC) != 0 )
  {
    LOBYTE(v6) = 0;
    v5 = &handle_level_irq;
    if ( (a2 & 4) != 0 )
      LOBYTE(v8) = 0;
    else
      v8 = 1 << (BYTE2(v2) & 7);
    v34 = v4 & (a2 << 29 >> 31);
    LOBYTE(v35) = v8;
LABEL_9:
    v9 = (v2 >> 28) & 0x1F;
    v10 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 40LL);
    v33 = *(_QWORD *)(a1 + 48);
    v11 = (v2 >> 12) & 0xFFFFFF00 | 0x11;
    v12 = *(__int64 **)(v10 + 152);
    v13 = *v12;
    v14 = *(_DWORD **)(*(_QWORD *)(*v12 + 56) + 40LL);
    if ( *(v14 - 1) != 1307277261 )
      __break(0x8228u);
    v7 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD, __int64))v14)(v12, v9, v11, 1);
    if ( (v7 & 0x80000000) == 0 )
    {
      v31 = v6;
      v15 = *(_DWORD **)(*(_QWORD *)(v13 + 56) + 48LL);
      v36 = v5;
      if ( *(v15 - 1) != 1860309901 )
        __break(0x8228u);
      v16 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v15)(1, (unsigned int)v9, v11, 2);
      v17 = *v12;
      v18 = v16;
      v19 = *(_DWORD **)(*(_QWORD *)(*v12 + 56) + 40LL);
      if ( *(v19 - 1) != 1307277261 )
        __break(0x8228u);
      v20 = ((__int64 (__fastcall *)(__int64 *, _QWORD, _QWORD, _QWORD))v19)(v12, (unsigned int)v9, v11, 0);
      if ( (v20 & 0x80000000) != 0 )
      {
        v7 = v20;
        v5 = v36;
      }
      else
      {
        v21 = *(_DWORD **)(*(_QWORD *)(v17 + 56) + 48LL);
        if ( *(v21 - 1) != 1860309901 )
          __break(0x8228u);
        v30 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64))v21)(0, (unsigned int)v9, v11, 2);
        v22 = raw_spin_lock_irqsave(v12 + 6);
        v23 = *(__int64 ***)(v10 + 152);
        v32 = v22;
        v24 = *v23;
        writel_relaxed(v18, (unsigned int *)(**v23 + v7));
        v25 = pmic_arb_wait_for_done(v10, *v24, v9, v11);
        if ( v25 )
        {
          v26 = v25;
          raw_spin_unlock_irqrestore(v12 + 6, v32);
          v5 = v36;
          v7 = v26;
        }
        else
        {
          v27 = *(_DWORD *)(*v24 + v7 + 24);
          v28 = **(_QWORD **)(v10 + 152);
          *(_DWORD *)(v20 + *(_QWORD *)(v28 + 8) + 16LL) = (unsigned __int16)((unsigned __int8)(BYTE1(v27) & ~(_BYTE)v4
                                                                                              | v34 & v4) << 8)
                                                         | ((unsigned __int8)(BYTE2(v27) & ~(_BYTE)v4 | v35 & v4) << 16)
                                                         | (unsigned __int8)(v27 & ~(_BYTE)v4 | v31 & v4);
          writel_relaxed(v30, (unsigned int *)(*(_QWORD *)(v28 + 8) + v20));
          v7 = pmic_arb_wait_for_done(v10, *(_QWORD *)(v28 + 8), v9, v11);
          raw_spin_unlock_irqrestore(v12 + 6, v32);
          v5 = v36;
          if ( !v7 )
          {
LABEL_25:
            *(_QWORD *)(*(_QWORD *)(a1 + 16) + 112LL) = v5;
            return v7;
          }
        }
      }
    }
    if ( (unsigned int)__ratelimit(&qpnpint_spmi_masked_write__rs, "qpnpint_spmi_masked_write") )
      dev_err(*(_QWORD *)(v33 + 40), "failed irqchip transaction on %x rc=%d\n", *(_DWORD *)(a1 + 4), v7);
    goto LABEL_25;
  }
  return (unsigned int)-22;
}
