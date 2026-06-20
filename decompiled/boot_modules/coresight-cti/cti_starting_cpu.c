__int64 __fastcall cti_starting_cpu(_QWORD *a1)
{
  __int64 v1; // x13
  __int64 v2; // x19
  int v3; // w8

  if ( (unsigned int)a1 >= 0x20 )
  {
    __break(0x5512u);
    *a1 = v1;
    return cti_dying_cpu((char *)a1 + 217);
  }
  else
  {
    v2 = cti_cpu_drvdata[(unsigned int)a1];
    if ( v2 )
    {
      raw_spin_lock(v2 + 56);
      v3 = *(_DWORD *)(v2 + 72);
      *(_BYTE *)(v2 + 77) = 1;
      if ( v3 )
      {
        if ( !(unsigned int)coresight_claim_device(*(_QWORD *)(v2 + 8)) )
        {
          cti_write_all_hw_regs((_QWORD *)v2);
          *(_BYTE *)(v2 + 76) = 1;
        }
      }
      raw_spin_unlock(v2 + 56);
    }
    return 0;
  }
}
