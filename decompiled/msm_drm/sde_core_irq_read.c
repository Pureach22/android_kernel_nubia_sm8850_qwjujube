__int64 __fastcall sde_core_irq_read(__int64 result, __int64 a2, __int64 a3)
{
  int v3; // w18
  __int64 v4; // x8
  __int64 (*v5)(void); // x8

  if ( !result )
    return result;
  result = *(_QWORD *)(result + 1896);
  if ( !result )
    return result;
  v4 = *(unsigned int *)(result + 28);
  if ( (unsigned int)v4 < 3 )
  {
    v5 = *(__int64 (**)(void))(result + 8 * v4 + 224);
    if ( v5 )
    {
      if ( (a2 & 0x80000000) == 0 )
      {
        if ( *((_DWORD *)v5 - 1) != -1814284393 )
          __break(0x8228u);
        return v5();
      }
      printk(&unk_27D931, "sde_core_irq_read");
    }
    return 0;
  }
  __break(0x5512u);
  if ( (v3 & 0x20000) == 0 )
    JUMPOUT(0x1046F4);
  return sde_core_irq_register_callback(result, a2, a3);
}
