unsigned __int64 __fastcall glink_smem_rx_avail(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  _QWORD *v3; // x19
  unsigned __int64 v4; // x1
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  unsigned __int64 v8; // x8
  unsigned __int64 result; // x0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[8];
  v1 = a1[9];
  v10[0] = 0;
  if ( !v2 )
  {
    v3 = a1;
    v4 = qcom_smem_get(*(unsigned int *)(v1 + 1024), 480, v10);
    if ( v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_6AFD);
      result = 0;
      goto LABEL_9;
    }
    v5 = v10[0];
    a1 = v3;
    v3[8] = v4;
    *v3 = v5;
  }
  v6 = *(unsigned int *)a1[7];
  v7 = *(unsigned int *)a1[6];
  v8 = *a1;
  if ( (unsigned int)v6 >= (unsigned int)v7 )
    result = (unsigned int)(v6 - v7);
  else
    result = v6 - v7 + *a1;
  v10[0] = result;
  if ( result > v8 )
  {
    result = 0;
    __break(0x800u);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
