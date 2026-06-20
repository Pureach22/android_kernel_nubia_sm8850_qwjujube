__int64 __fastcall etm_event_get_path(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9

  v2 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  v3 = *(_QWORD *)((char *)&etm_ctxt + _ReadStatusReg(TPIDR_EL1) + 56);
  if ( v3 )
  {
    if ( (unsigned int)v2 >= 0x20 )
    {
      __break(0x5512u);
      JUMPOUT(0x5C2C8);
    }
    return *(_QWORD *)(_per_cpu_offset[v2] + *(_QWORD *)(v3 + 64));
  }
  else
  {
    printk(&unk_12700, a2);
    return 0;
  }
}
