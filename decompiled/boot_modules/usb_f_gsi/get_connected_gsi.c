__int64 get_connected_gsi()
{
  __int64 result; // x0

  if ( (!qword_FBF0 || (result = *(_QWORD *)(qword_FBF0 + 176)) == 0 || !*(_DWORD *)(result + 272))
    && (!qword_FC30 || (result = *(_QWORD *)(qword_FC30 + 176)) == 0 || !*(_DWORD *)(result + 272))
    && (!qword_FC70 || (result = *(_QWORD *)(qword_FC70 + 176)) == 0 || !*(_DWORD *)(result + 272))
    && (!qword_FCB0 || (result = *(_QWORD *)(qword_FCB0 + 176)) == 0 || !*(_DWORD *)(result + 272))
    && (!qword_FCF0 || (result = *(_QWORD *)(qword_FCF0 + 176)) == 0 || !*(_DWORD *)(result + 272)) )
  {
    if ( !qword_FD30 )
      return 0;
    result = *(_QWORD *)(qword_FD30 + 176);
    if ( !result || !*(_DWORD *)(result + 272) )
      return 0;
  }
  return result;
}
