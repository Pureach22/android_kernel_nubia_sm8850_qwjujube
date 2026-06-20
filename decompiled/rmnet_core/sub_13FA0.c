__int64 __fastcall sub_13FA0(__int64 a1)
{
  __int16 v1; // w27

  return rmnet_frag_flow_command(a1 & 0xFFFFFFFFF801FFFFLL | ((unsigned __int64)(v1 & 0x3FF) << 17));
}
