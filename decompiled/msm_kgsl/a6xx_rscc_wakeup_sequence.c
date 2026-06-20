__int64 __fastcall a6xx_rscc_wakeup_sequence(__int64 a1)
{
  int *v2; // x8
  __int64 v4; // x1
  int v5; // w22
  const char *v6; // x0
  int v8; // w8
  __int64 result; // x0
  unsigned __int64 v14; // x9
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  _X20 = (unsigned __int64 *)(a1 - 352);
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_QWORD *)(a1 - 352) & 8) == 0 )
    goto LABEL_21;
  v2 = *(int **)(a1 + 14264);
  v15 = 0;
  v4 = 156993;
  v5 = *v2;
  if ( (unsigned int)(*v2 - 621) >= 2 )
  {
    if ( v5 == 660 )
    {
LABEL_14:
      v4 = 148835;
      goto LABEL_15;
    }
    if ( v5 != 662 )
    {
      v6 = *((const char **)v2 + 3);
      if ( !v6 || strcmp(v6, "qcom,adreno-gpu-a642l") )
      {
        if ( v5 == 643 || v5 == 663 )
          v8 = 2652;
        else
          v8 = 2619;
        v4 = (unsigned int)(v8 + 146183);
        goto LABEL_15;
      }
      goto LABEL_14;
    }
  }
LABEL_15:
  gmu_core_regread(a1, v4, &v15);
  if ( (v15 & 1) == 0 && (unsigned int)__ratelimit(&a6xx_rscc_wakeup_sequence__rs, "a6xx_rscc_wakeup_sequence") )
    dev_info(*(_QWORD *)(a1 + 1544) + 16LL, "GMEM CLAMP IO not set while GFX rail off\n");
  gmu_core_regwrite(a1, 146183, 2);
  __dsb(0xEu);
  if ( (unsigned int)gmu_core_timed_poll_check(a1, 146184, 2, 100, 2) )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Failed to do GPU RSC power on\n");
LABEL_25:
    result = 4294967186LL;
    goto LABEL_22;
  }
  if ( (unsigned int)timed_poll_check_rscc(a1, 257, 0, 100, 0xFFFFFFFFLL) )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GPU RSC sequence stuck in waking up GPU\n");
    goto LABEL_25;
  }
  gmu_core_regwrite(a1, 146183, 0);
  __asm { PRFM            #0x11, [X20] }
  do
    v14 = __ldxr(_X20);
  while ( __stxr(v14 & 0xFFFFFFFFFFFFFFF7LL, _X20) );
LABEL_21:
  result = 0;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
