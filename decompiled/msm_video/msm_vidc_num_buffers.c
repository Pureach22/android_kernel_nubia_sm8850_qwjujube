__int64 __fastcall msm_vidc_num_buffers(__int64 result, unsigned int a2, int a3)
{
  __int64 v3; // x8
  _QWORD *v4; // x8
  _QWORD *v5; // x9

  if ( a2 == 2 )
  {
    v3 = 2544;
  }
  else
  {
    if ( a2 != 1 )
    {
      if ( !result )
        return result;
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_94891, "err ", result + 340, "msm_vidc_num_buffers", a2);
      return 0;
    }
    v3 = 2504;
  }
  v4 = (_QWORD *)(result + v3);
  v5 = (_QWORD *)*v4;
  if ( (_QWORD *)*v4 == v4 )
    return 0;
  result = 0;
  do
  {
    if ( *((_DWORD *)v5 + 6) == a2 )
    {
      if ( ((_DWORD)v5[10] & a3) != 0 )
        result = (unsigned int)(result + 1);
      else
        result = (unsigned int)result;
    }
    v5 = (_QWORD *)*v5;
  }
  while ( v5 != v4 );
  return result;
}
