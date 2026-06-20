unsigned __int64 __fastcall mem_buf_relinquish_mem(__int64 a1)
{
  unsigned int v2; // w1
  unsigned __int64 result; // x0
  unsigned __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // [xsp+8h] [xbp-38h] BYREF
  int *v7; // [xsp+10h] [xbp-30h]
  int *v8; // [xsp+18h] [xbp-28h]
  __int64 v9; // [xsp+20h] [xbp-20h]
  __int64 v10; // [xsp+28h] [xbp-18h]
  int v11; // [xsp+30h] [xbp-10h] BYREF
  int v12; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+38h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 24);
  v11 = 7;
  v12 = 3;
  v8 = nullptr;
  v9 = 0;
  v6 = 0;
  v7 = nullptr;
  if ( v2 == -1 )
  {
    result = dup_gh_sgl_desc_to_sgt(*(_QWORD *)(a1 + 16));
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = result;
      LODWORD(v6) = 1;
      v7 = &v12;
      v8 = &v11;
      HIDWORD(v9) = 1;
      v10 = 0;
      if ( !(unsigned int)mem_buf_assign_mem(0, result, &v6) )
      {
        v5 = *(unsigned int *)(a1 + 88);
        *(_DWORD *)(a1 + 24) = v9;
        _mem_buf_relinquish_mem(v5);
      }
      sg_free_table(v4);
      result = kfree(v4);
    }
  }
  else if ( !*(_DWORD *)(a1 + 28) || (result = mem_buf_unmap_mem_s2(v2), !(_DWORD)result) )
  {
    result = _mem_buf_relinquish_mem(*(unsigned int *)(a1 + 88));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
