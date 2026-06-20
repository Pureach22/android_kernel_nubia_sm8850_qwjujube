__int64 __fastcall sw_trig_store(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v6; // x21
  int v7; // w8
  __int64 result; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v9[0] = 0;
  v7 = kstrtoull(a3, 16, v9);
  result = -22;
  if ( !v7 && v9[0] <= 1u )
  {
    if ( *(_DWORD *)(v6 + 328) <= (unsigned int)*(unsigned __int8 *)(v6 + 332) )
    {
      dev_err(a1, "Select link list to program using curr_list\n");
      result = -22;
    }
    else
    {
      result = a4;
      *(_BYTE *)(*(_QWORD *)(v6 + 136) + *(unsigned __int8 *)(v6 + 332)) = v9[0];
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
