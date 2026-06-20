__int64 __fastcall ipa_rm_stat(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  int v6; // w24
  unsigned int v7; // w22
  unsigned int v8; // w0
  int v9; // w22
  unsigned int v10; // w20
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  result = 22;
  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  if ( !a1 || a2 < 0 )
    goto LABEL_11;
  v5 = raw_spin_lock_irqsave(ipa_rm_ctx + 16);
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    if ( (v7 & 1) != 0 || (unsigned int)ipa_rm_dep_graph_get_resource(*(_QWORD *)ipa_rm_ctx, v7, v11) )
      goto LABEL_4;
    v8 = ipa_rm_resource_producer_print_stat(v11[0], a1 + v6, (unsigned int)(a2 - v6));
    if ( (v8 & 0x80000000) != 0 )
      break;
    v6 += v8;
LABEL_4:
    if ( ++v7 == 22 )
    {
      v9 = scnprintf(
             a1 + v6,
             a2 - v6,
             "All prod bandwidth: %d, All cons bandwidth: %d\n",
             *(_DWORD *)(ipa_rm_ctx + 112)
           + *(_DWORD *)(ipa_rm_ctx + 120)
           + *(_DWORD *)(ipa_rm_ctx + 128)
           + *(_DWORD *)(ipa_rm_ctx + 136)
           + *(_DWORD *)(ipa_rm_ctx + 144)
           + *(_DWORD *)(ipa_rm_ctx + 152)
           + *(_DWORD *)(ipa_rm_ctx + 160)
           + *(_DWORD *)(ipa_rm_ctx + 168)
           + *(_DWORD *)(ipa_rm_ctx + 176)
           + *(_DWORD *)(ipa_rm_ctx + 184)
           + *(_DWORD *)(ipa_rm_ctx + 192),
             *(_DWORD *)(ipa_rm_ctx + 116)
           + *(_DWORD *)(ipa_rm_ctx + 124)
           + *(_DWORD *)(ipa_rm_ctx + 132)
           + *(_DWORD *)(ipa_rm_ctx + 140)
           + *(_DWORD *)(ipa_rm_ctx + 148)
           + *(_DWORD *)(ipa_rm_ctx + 156)
           + *(_DWORD *)(ipa_rm_ctx + 164)
           + *(_DWORD *)(ipa_rm_ctx + 172)
           + *(_DWORD *)(ipa_rm_ctx + 180)
           + *(_DWORD *)(ipa_rm_ctx + 188)
           + *(_DWORD *)(ipa_rm_ctx + 196))
         + v6;
      v10 = scnprintf(
              a1 + v9,
              a2 - v9,
              "Voting: voltage %d, bandwidth %d\n",
              *(_DWORD *)(ipa_rm_ctx + 108),
              *(_DWORD *)(ipa_rm_ctx + 200))
          + v9;
      goto LABEL_10;
    }
  }
  v10 = v8;
LABEL_10:
  raw_spin_unlock_irqrestore(ipa_rm_ctx + 16, v5);
  result = v10;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
