__int64 __fastcall rmnet_offload_knob_get(unsigned int a1)
{
  if ( a1 <= 3 )
    return *((_QWORD *)&rmnet_offload_knobs + 8 * (unsigned __int64)a1);
  else
    return -1;
}
