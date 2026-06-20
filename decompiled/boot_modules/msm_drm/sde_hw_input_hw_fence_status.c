__int64 __fastcall sde_hw_input_hw_fence_status(__int64 *a1, unsigned __int64 *a2, unsigned __int64 *a3)
{
  __int64 v5; // x8
  __int64 v7; // x8
  __int64 v8; // x10
  int v9; // w23
  unsigned int v10; // w22
  unsigned int v11; // w21
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x9
  int v16; // w0
  __int64 result; // x0
  __int64 v18; // [xsp+8h] [xbp-48h] BYREF
  __int64 v19; // [xsp+10h] [xbp-40h]
  __int64 v20; // [xsp+18h] [xbp-38h]
  __int64 v21; // [xsp+20h] [xbp-30h]
  __int64 v22; // [xsp+28h] [xbp-28h] BYREF
  __int64 v23; // [xsp+30h] [xbp-20h]
  __int64 v24; // [xsp+38h] [xbp-18h]
  __int64 v25; // [xsp+40h] [xbp-10h]
  __int64 v26; // [xsp+48h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 && (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL && a3 && (unsigned __int64)a3 < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = a1[1];
    v18 = *a1;
    v19 = v5;
    v7 = a1[2];
    v8 = a1[3];
    v9 = *(_DWORD *)(a1[5] + 68);
    LODWORD(v19) = 0;
    v20 = v7;
    v21 = v8;
    v10 = sde_reg_read((__int64)&v18, v9 + 16);
    *a2 = v10 | (unsigned __int64)(sde_reg_read((__int64)&v18, v9 + 20) << 32);
    v11 = sde_reg_read((__int64)&v18, v9 + 24);
    *a3 = v11 | (unsigned __int64)(sde_reg_read((__int64)&v18, v9 + 28) << 32);
    v12 = a1[1];
    v22 = *a1;
    v23 = v12;
    v13 = a1[2];
    v14 = a1[3];
    v15 = a1[5];
    LODWORD(v23) = 0;
    v24 = v13;
    v25 = v14;
    v16 = sde_reg_read((__int64)&v22, *(_DWORD *)(v15 + 68) + 12);
    result = sde_reg_write(
               (__int64)&v22,
               *(_DWORD *)(a1[5] + 68) + 12,
               v16 & 0xFFFFFFFC | 2,
               "mdp->caps->hw_fence_mdp_offset + MDP_CTL_HW_FENCE_ID_TIMESTAMP_CTRL");
    __dsb(0xEu);
  }
  else
  {
    result = printk(&unk_246EAC, "sde_hw_input_hw_fence_status");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
