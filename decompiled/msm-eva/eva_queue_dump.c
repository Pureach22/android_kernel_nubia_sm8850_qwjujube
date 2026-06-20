__int64 __fastcall eva_queue_dump(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  _QWORD *v3; // x8
  _QWORD *v4; // x9
  __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x8
  __int64 v10; // x12
  __int64 result; // x0
  unsigned __int64 v12; // x8
  __int64 v13; // x1
  __int64 v14; // x2
  void *v15; // x0
  unsigned __int64 StatusReg; // x8

  v3 = *(_QWORD **)(a1 + 8);
  if ( v3 && *(_QWORD *)(a1 + 24) )
  {
    v4 = (_QWORD *)(a2 + a3);
    if ( (unsigned __int64)v4 >= a2 && v4 < v4 + 0x20000 )
    {
      v6 = v3[1];
      v5 = v3[2];
      *v4 = *v3;
      v4[1] = v6;
      v4[2] = v5;
      v8 = v3[5];
      v7 = v3[6];
      v10 = v3[3];
      v9 = v3[4];
      v4[5] = v8;
      v4[6] = v7;
      v4[3] = v10;
      v4[4] = v9;
      memcpy(v4 + 7, *(const void **)(a1 + 24), *(unsigned int *)(a1 + 32));
      return 0;
    }
    result = 0xFFFFFFFFLL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v13 = *(unsigned int *)(StatusReg + 1800);
      v14 = *(unsigned int *)(StatusReg + 1804);
      v15 = &unk_85DD0;
      goto LABEL_12;
    }
  }
  else
  {
    result = 0xFFFFFFFFLL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      v13 = *(unsigned int *)(v12 + 1800);
      v14 = *(unsigned int *)(v12 + 1804);
      v15 = &unk_834A6;
LABEL_12:
      printk(v15, v13, v14, &unk_8E7CE);
      return 0xFFFFFFFFLL;
    }
  }
  return result;
}
