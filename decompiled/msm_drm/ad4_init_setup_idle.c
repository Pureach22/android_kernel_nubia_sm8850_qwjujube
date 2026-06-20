__int64 __fastcall ad4_init_setup_idle(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x8

  if ( **(_QWORD **)(a2 + 8) )
  {
    result = ((__int64 (__fastcall *)(__int64))ad4_init_setup)(a1);
    if ( !(_DWORD)result )
    {
      if ( *(_DWORD *)(a1 + 64) <= 4u )
        JUMPOUT(0x164530);
      goto LABEL_9;
    }
  }
  else
  {
    v4 = *(unsigned int *)(a1 + 64);
    if ( (unsigned int)v4 >= 5 )
    {
LABEL_9:
      __break(0x5512u);
      goto LABEL_10;
    }
    if ( ((144 * v4) | 4uLL) > 0x2D0 )
    {
LABEL_10:
      __break(1u);
      JUMPOUT(0x164680);
    }
    result = 0;
    info[36 * (unsigned int)v4 + 1] &= ~2u;
  }
  return result;
}
