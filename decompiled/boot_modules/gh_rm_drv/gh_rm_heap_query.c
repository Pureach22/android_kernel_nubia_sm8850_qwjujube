__int64 __fastcall gh_rm_heap_query(int a1, unsigned __int8 a2, unsigned int **a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v8; // x2
  unsigned int v9; // w19
  _DWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = a1;
  v10[1] = a2;
  result = gunyah_rm_call(rm, 1358954548, v10, 8, a3, a4);
  if ( a2 == 2 )
  {
    v8 = 32;
  }
  else if ( a2 == 1 )
  {
    v8 = 4LL * **a3 + 4;
  }
  else
  {
    v8 = 0;
  }
  if ( *a4 != v8 )
  {
    printk(&unk_123CE, "gh_rm_heap_query");
    LODWORD(result) = -22;
    goto LABEL_10;
  }
  if ( (_DWORD)result )
  {
LABEL_10:
    v9 = result;
    printk(&unk_126F2, "gh_rm_heap_query");
    result = v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
