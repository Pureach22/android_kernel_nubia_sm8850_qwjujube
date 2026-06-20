__int64 __fastcall cti_trig_store(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v6; // x22
  __int64 v7; // x20
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v9[0] = 0;
  v7 = -22;
  if ( !(unsigned int)kstrtoull(a3, 16, v9) && v9[0] <= 1u )
  {
    mutex_lock(v6 + 24);
    if ( *(_DWORD *)(v6 + 328) <= (unsigned int)*(unsigned __int8 *)(v6 + 332) )
    {
      dev_err(a1, "Select link list to program using curr_list\n");
    }
    else if ( (*(_BYTE *)(*(_QWORD *)(v6 + 120) + *(unsigned __int8 *)(v6 + 332)) & 1) != 0 )
    {
      v7 = -16;
    }
    else
    {
      v7 = a4;
      *(_BYTE *)(*(_QWORD *)(v6 + 336) + *(unsigned __int8 *)(v6 + 332)) = v9[0] != 0;
    }
    mutex_unlock(v6 + 24);
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
