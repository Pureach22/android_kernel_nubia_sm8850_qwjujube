__int64 __fastcall replicator_enable(__int64 a1, __int64 a2, unsigned int *a3)
{
  _QWORD *v4; // x24
  unsigned int v5; // w23
  unsigned int v7; // w21
  __int64 v8; // x23
  int v9; // w22
  unsigned int v10; // w0
  int v11; // w8
  _BOOL4 v12; // w9
  int v13; // w25
  unsigned int v14; // w22
  unsigned int *v15; // x8
  unsigned int v22; // w9

  v4 = *(_QWORD **)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v4 + 4);
  if ( *((_BYTE *)v4 + 88) != 1 )
  {
    v5 = -22;
    goto LABEL_5;
  }
  if ( !a3[14] && *v4 )
  {
    v7 = *a3;
    v8 = v4[3];
    writel_relaxed(3316436565LL, *v4 + 4016LL);
    __dsb(0xFu);
    v9 = readl_relaxed((unsigned int *)*v4);
    v10 = readl_relaxed((unsigned int *)(*v4 + 4LL));
    v11 = *((unsigned __int8 *)v4 + 36);
    if ( v9 )
      v11 = 0;
    v12 = v10 == 0;
    if ( (v11 & v12) != 0 )
      v13 = 255;
    else
      v13 = v9;
    if ( (v11 & v12) != 0 )
      v14 = 255;
    else
      v14 = v10;
    if ( v13 != 255 || v14 != 255 || (v5 = coresight_claim_device_unlocked(v8)) == 0 )
    {
      if ( !v7 )
      {
LABEL_21:
        writel_relaxed(v7, *v4);
        writel_relaxed(v14, *v4 + 4LL);
        v5 = 0;
        goto LABEL_23;
      }
      if ( v7 == 1 )
      {
        v14 = 0;
        v7 = v13;
        goto LABEL_21;
      }
      __break(0x800u);
      v5 = -22;
    }
LABEL_23:
    v15 = (unsigned int *)*v4;
    __dsb(0xFu);
    writel_relaxed(0, v15 + 1004);
    if ( v5 )
      goto LABEL_5;
  }
  _X8 = a3 + 14;
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 + 1, _X8) );
  v5 = 0;
LABEL_5:
  raw_spin_unlock_irqrestore(v4 + 4);
  return v5;
}
