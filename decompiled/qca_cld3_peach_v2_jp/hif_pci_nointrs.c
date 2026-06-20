__int64 __fastcall hif_pci_nointrs(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  __int64 v10; // x25
  __int64 v11; // x0
  int v12; // w21
  unsigned int v13; // w8
  signed int v14; // w9
  __int64 v15; // x26
  signed int v16; // w22
  unsigned int v17; // w24
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w1
  int v28; // [xsp+Ch] [xbp-14h] BYREF
  int v29; // [xsp+10h] [xbp-10h] BYREF
  int v30; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)(a1 + 587) = 1;
  result = ce_unregister_irq(a1, 0xFFFF);
  if ( *(_BYTE *)(a1 + 585) )
  {
    hif_pci_deconfigure_grp_irq(a1, v3, v4, v5, v6, v7, v8, v9);
    v10 = *(_QWORD *)(a1 + 27400);
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL);
    v30 = 0;
    v28 = 0;
    v29 = 0;
    result = pld_get_user_msi_assignment(v11, (__int64)"CE", (__int64)&v29, (__int64)&v30, (__int64)&v28);
    if ( (_DWORD)result )
    {
      if ( (_DWORD)result == -22 )
      {
        if ( *(int *)(a1 + 30776) < 1 )
        {
          result = free_irq(*(unsigned int *)(a1 + 30896), a1);
        }
        else
        {
          v12 = 0;
          do
          {
            result = free_irq((unsigned int)(v12 + *(_DWORD *)(a1 + 30896)), a1);
            ++v12;
          }
          while ( v12 < *(_DWORD *)(a1 + 30776) );
          *(_DWORD *)(a1 + 30776) = 0;
        }
LABEL_18:
        *(_BYTE *)(a1 + 585) = 0;
        goto LABEL_19;
      }
    }
    else
    {
      v13 = *(_DWORD *)(a1 + 656);
      if ( v13 )
      {
        v14 = 0;
        v15 = a1 + 26448;
        do
        {
          v16 = v14;
          if ( (*(_BYTE *)(v10 + 32LL * v14) & 8) == 0 )
          {
            if ( (unsigned int)v14 >= 0xC )
              __break(0x5512u);
            if ( *(_BYTE *)(v15 + 56LL * v14 + 44) == 1 )
            {
              v17 = *(_DWORD *)(a1 + 30848 + 4LL * v14);
              v18 = _irq_apply_affinity_hint(v17, 0, 1);
              qdf_status_from_os_return(v18);
              qdf_trace_msg(
                0x3Du,
                8u,
                "%s: %s: (ce_id %d, irq %d)",
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                "hif_ce_srng_free_irq",
                "hif_ce_srng_free_irq",
                (unsigned int)v16,
                v17);
              result = pld_srng_free_irq(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), v17, v15 + 56LL * v16);
              v13 = *(_DWORD *)(a1 + 656);
            }
          }
          v14 = v16 + 1;
        }
        while ( v16 + 1 < v13 );
      }
    }
    v27 = *(_DWORD *)(a1 + 2572);
    if ( v27 )
      result = pld_srng_free_irq(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), v27, a1);
    *(_DWORD *)(a1 + 2572) = 0;
    goto LABEL_18;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
