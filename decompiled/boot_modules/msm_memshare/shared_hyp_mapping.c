__int64 __fastcall shared_hyp_mapping(int a1)
{
  __int64 *v1; // x20
  unsigned __int64 v2; // x19
  __int64 result; // x0
  _DWORD *v4; // x3
  unsigned int v5; // w4
  int v6; // w9
  unsigned int v7; // w4
  unsigned __int64 StatusReg; // x21
  __int64 v9; // x22
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 8;
  if ( a1 >= 10 )
  {
    result = dev_err(*(_QWORD *)memsh_drv, "memshare: hypervisor mapping failure for invalid client\n");
    goto LABEL_13;
  }
  if ( (unsigned int)a1 >= 0xB )
  {
LABEL_10:
    __break(0x5512u);
  }
  else
  {
    v1 = &memblock[12 * (unsigned int)a1];
    v2 = 8LL * *((unsigned int *)v1 + 9);
    result = _kmalloc_noprof(v2, 3520);
    v4 = (_DWORD *)result;
    if ( !result )
      goto LABEL_13;
    while ( *((_DWORD *)v1 + 9) )
    {
      if ( v2 )
      {
        v5 = *((_DWORD *)v1 + 9);
        v6 = *((_DWORD *)v1 + 12);
        *v4 = *((_DWORD *)v1 + 10);
        v4[1] = v6;
        if ( v5 < 2 )
          break;
        if ( v2 != 8 )
        {
          v4[2] = *((_DWORD *)v1 + 11);
          if ( v2 >= 0xC )
          {
            v7 = *((_DWORD *)v1 + 9);
            v4[3] = *((_DWORD *)v1 + 13);
            if ( v7 <= 2 )
              break;
            goto LABEL_10;
          }
        }
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v9 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v2 = 8LL * *((unsigned int *)v1 + 9);
      result = _kmalloc_noprof(v2, 3520);
      v4 = (_DWORD *)result;
      *(_QWORD *)(StatusReg + 80) = v9;
      if ( !result )
        goto LABEL_13;
    }
  }
  result = qcom_scm_assign_mem(v1[9], *((unsigned int *)v1 + 14), v10);
  if ( (_DWORD)result )
    result = dev_err(
               *(_QWORD *)memsh_drv,
               "memshare: qcom_scm_assign_mem failed size=%u err=%d\n",
               *((_DWORD *)v1 + 14),
               result);
  else
    *((_BYTE *)v1 + 89) = 1;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
