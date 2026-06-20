__int64 __fastcall sde_hw_hw_fence_timestamp_ctrl(__int64 *a1, char a2, char a3)
{
  __int64 v3; // x8
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x9
  int v10; // w0
  int v11; // w8
  __int64 result; // x0
  __int64 v13; // [xsp+8h] [xbp-28h] BYREF
  __int64 v14; // [xsp+10h] [xbp-20h]
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v3 = a1[1];
    v13 = *a1;
    v14 = v3;
    v7 = a1[2];
    v8 = a1[3];
    v9 = a1[5];
    LODWORD(v14) = 0;
    v15 = v7;
    v16 = v8;
    v10 = sde_reg_read((__int64)&v13, *(_DWORD *)(v9 + 68) + 12);
    if ( (a3 & 1) != 0 )
      v11 = 2;
    else
      v11 = 0;
    result = sde_reg_write(
               (__int64)&v13,
               *(_DWORD *)(a1[5] + 68) + 12,
               v11 & 0xFFFFFFFE | a2 & 1 | v10 & 0xFFFFFFFC,
               "mdp->caps->hw_fence_mdp_offset + MDP_CTL_HW_FENCE_ID_TIMESTAMP_CTRL");
  }
  else
  {
    result = printk(&unk_243CD5, "sde_hw_hw_fence_timestamp_ctrl");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
