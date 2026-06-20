__int64 __fastcall carveout_setup_vmperm(__int64 a1, __int64 a2)
{
  char v2; // w8
  __int64 result; // x0
  __int64 v5; // x19
  unsigned int v6; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  __int64 v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a1 + 88);
  v7 = 0;
  v8[0] = 0;
  v6 = 0;
  if ( (v2 & 1) != 0 )
  {
    LODWORD(result) = get_vmperm_from_ion_flags(*(unsigned int *)(a1 - 8), v8, &v7, &v6);
    if ( (_DWORD)result )
    {
      result = (int)result;
    }
    else
    {
      v5 = mem_buf_vmperm_alloc_staticvm(a2 + 80, v8[0], v7, v6, qcom_sg_release, a2 + 168);
      kfree(v8[0]);
      kfree(v7);
      result = v5;
    }
  }
  else
  {
    result = mem_buf_vmperm_alloc(a2 + 80, qcom_sg_release, a2 + 168);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
