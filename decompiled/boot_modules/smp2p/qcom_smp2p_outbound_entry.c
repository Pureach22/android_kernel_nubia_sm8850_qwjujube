__int64 __fastcall qcom_smp2p_outbound_entry(_QWORD *a1, _QWORD *a2, __int64 a3)
{
  const char *v6; // x22
  __int64 v7; // x23
  size_t v8; // x0
  unsigned __int64 v9; // x2
  __int64 v10; // x8
  __int64 v11; // x10
  unsigned __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (const char *)a2[3];
  v7 = a1[2];
  v14 = 0;
  v15 = 0;
  v8 = strnlen(v6, 0x10u);
  if ( v8 == -1 )
  {
    _fortify_panic(2, -1, 0);
LABEL_12:
    _fortify_panic(7, 16, v9);
LABEL_13:
    __break(0x5512u);
  }
  if ( v8 == 16 )
    v9 = 16;
  else
    v9 = v8 + 1;
  if ( v9 >= 0x11 )
    goto LABEL_12;
  sized_strscpy(&v14, v6);
  if ( *(unsigned __int16 *)(v7 + 14) >= 0x10uLL )
    goto LABEL_13;
  v10 = v7 + 20LL * *(unsigned __int16 *)(v7 + 14);
  v11 = v14;
  *(_QWORD *)(v10 + 28) = v15;
  *(_QWORD *)(v10 + 20) = v11;
  a2[4] = v10 + 36;
  ++*(_WORD *)(v7 + 14);
  v12 = qcom_smem_state_register(a3, smp2p_state_ops, a2);
  a2[11] = v12;
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*a1, "failed to register qcom_smem_state\n");
    result = *((unsigned int *)a2 + 22);
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
