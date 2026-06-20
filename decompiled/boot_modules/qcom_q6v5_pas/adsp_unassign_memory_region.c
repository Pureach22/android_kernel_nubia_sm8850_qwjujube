__int64 __fastcall adsp_unassign_memory_region(__int64 result)
{
  __int64 v1; // x1
  int *v2; // x19
  __int64 v3; // x2
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 v8; // x1
  char v9; // w2
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_DWORD *)(result + 744) || (*(_BYTE *)(result + 752) & 1) != 0 || *(int *)(result + 748) < 1 )
    goto LABEL_13;
  v1 = *(_QWORD *)(result + 720);
  v2 = (int *)result;
  v3 = result + 760;
  v4 = *(_QWORD *)(result + 664);
  v10[0] = 0x600000003LL;
  result = qcom_scm_assign_mem(v4, v1, v3, v10, 1);
  if ( (result & 0x80000000) != 0 )
    result = dev_err(*(_QWORD *)v2, "unassign memory failed\n");
  if ( v2[187] < 2 )
    goto LABEL_13;
  v5 = *((_QWORD *)v2 + 84);
  v6 = *((_QWORD *)v2 + 91);
  v10[0] = 0x600000003LL;
  result = qcom_scm_assign_mem(v5, v6, v2 + 192, v10, 1);
  if ( (result & 0x80000000) != 0 )
    result = dev_err(*(_QWORD *)v2, "unassign memory failed\n");
  if ( v2[187] < 3 )
    goto LABEL_13;
  v7 = *((_QWORD *)v2 + 85);
  v8 = *((_QWORD *)v2 + 92);
  v10[0] = 0x600000003LL;
  result = qcom_scm_assign_mem(v7, v8, v2 + 194, v10, 1);
  if ( (result & 0x80000000) != 0 )
    result = dev_err(*(_QWORD *)v2, "unassign memory failed\n");
  if ( v2[187] > 3 )
  {
    v10[0] = 0x600000003LL;
    __break(0x5512u);
    if ( (v9 & 2) != 0 )
      JUMPOUT(0x63A8);
    return adsp_minidump();
  }
  else
  {
LABEL_13:
    _ReadStatusReg(SP_EL0);
  }
  return result;
}
