__int64 __fastcall hif_exec_grp_irq_enable(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x19
  unsigned __int64 v3; // x20
  __int64 v4; // x22

  if ( *(_DWORD *)(result + 16) )
  {
    v1 = *(_QWORD *)(result + 8);
    v2 = result;
    v3 = 0;
    v4 = result + 120;
    do
    {
      if ( v3 == 25 )
      {
        __break(0x5512u);
        JUMPOUT(0x5CCB60);
      }
      result = pld_srng_enable_irq(*(_QWORD *)(*(_QWORD *)(v1 + 576) + 40LL), *(_DWORD *)(v4 + 4 * v3++));
    }
    while ( v3 < *(unsigned int *)(v2 + 16) );
  }
  return result;
}
