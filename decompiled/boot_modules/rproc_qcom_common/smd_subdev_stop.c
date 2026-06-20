__int64 __fastcall smd_subdev_stop(__int64 result, char a2, __int64 a3)
{
  __int64 *v4; // x9
  __int64 v5; // x1
  const char *v6; // x3
  __int64 v7; // x19

  if ( *(_QWORD *)(result + 64) )
  {
    v4 = *(__int64 **)(*(_QWORD *)(result + 48) + 96LL);
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    if ( (a2 & 1) != 0 )
      v6 = "crash stop";
    else
      v6 = "stop";
    v7 = result;
    result = qcom_smd_unregister_edge(*(_QWORD *)(result + 64), v5, a3, v6);
    *(_QWORD *)(v7 + 64) = 0;
  }
  return result;
}
