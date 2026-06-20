__int64 __fastcall gh_rm_add_heap_memory(int a1, int a2)
{
  __int64 result; // x0
  unsigned int v3; // w19
  _DWORD v4[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v5; // [xsp+18h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = a1;
  v4[1] = 0;
  v4[2] = a2;
  result = gunyah_rm_call(rm, 1358954546, v4, 12, 0, 0);
  if ( (_DWORD)result )
  {
    v3 = result;
    printk(&unk_126F2, "__gh_rm_heap_memory");
    result = v3;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
