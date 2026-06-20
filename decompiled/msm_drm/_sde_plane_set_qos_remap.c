__int64 __fastcall sde_plane_set_qos_remap(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x10
  __int64 v4; // x9
  int v5; // w8
  char v6; // w11
  int v7; // w7
  int v8; // w9
  int v9; // w5
  void *v10; // x0
  _DWORD v11[5]; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)result )
  {
    v10 = &unk_26FEB0;
    goto LABEL_16;
  }
  v1 = *(_QWORD *)(*(_QWORD *)result + 56LL);
  if ( !v1 || (v2 = *(_QWORD *)(v1 + 8)) == 0 )
  {
    v10 = &unk_25EA03;
LABEL_16:
    result = printk(v10, "_sde_plane_set_qos_remap");
    goto LABEL_17;
  }
  v3 = *(_QWORD *)(result + 2208);
  if ( !v3 )
  {
    v10 = &unk_262833;
    goto LABEL_16;
  }
  if ( (*(_BYTE *)(result + 2388) & 1) == 0 )
  {
    v4 = *(_QWORD *)(v3 + 56);
    v5 = 0;
    v6 = *(_BYTE *)(result + 2381);
    v7 = *(_DWORD *)(v4 + 56);
    v8 = *(_DWORD *)(v4 + 60);
    v9 = *(_DWORD *)(v3 + 48) - 1;
    v11[0] = 0;
    v11[1] = v7;
    v11[2] = v8;
    v11[3] = v9;
    if ( (v6 & 1) == 0 )
    {
      if ( *(_DWORD *)(result + 2384) == 2 )
        v5 = 5;
      else
        v5 = 1;
    }
    v11[4] = v5;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "plane%d pipe:%d vbif:%d xin:%d rt:%d, clk_ctrl:%d\n",
        *(_DWORD *)(result + 104),
        v9,
        0,
        v7,
        v5,
        v8);
    result = sde_vbif_set_qos_remap(v2, v11);
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
