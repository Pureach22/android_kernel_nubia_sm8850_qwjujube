__int64 __fastcall gen8_hwsched_preempt_info_get(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  int vrb_register; // w21
  int v6; // w0
  int v7; // w8
  __int64 result; // x0
  unsigned int v9; // w20
  __int64 v10; // x20
  __int64 v11; // x20
  int v12; // [xsp+Ch] [xbp-14h] BYREF
  int v13; // [xsp+10h] [xbp-10h] BYREF
  int v14; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 8664);
  v14 = 0;
  v12 = 0;
  v13 = 0;
  vrb_register = gmu_core_get_vrb_register(v4, 6, &v14);
  v6 = gmu_core_get_vrb_register(*(_QWORD *)(a1 + 8664), 7, &v13);
  v7 = v6 | vrb_register | gmu_core_get_vrb_register(*(_QWORD *)(a1 + 8664), 8, &v12);
  if ( v7 )
  {
    result = v7;
  }
  else
  {
    v9 = scnprintf(a2, 4096, "%-8s %-8s\n", "Level:", "Count");
    v10 = (unsigned int)scnprintf(a2 + v9, 4096 - v9, "%-8s 0x%-8x\n", "L0:", v14) + v9;
    v11 = (unsigned int)scnprintf(a2 + v10, (unsigned int)(4096 - v10), "%-8s 0x%-8x\n", "L1A:", v13)
        + (unsigned int)v10;
    result = (unsigned int)scnprintf(a2 + v11, (unsigned int)(4096 - v11), "%-8s 0x%-8x\n", "L1B:", v12)
           + (unsigned int)v11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
