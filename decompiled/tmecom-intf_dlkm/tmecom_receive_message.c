__int64 __fastcall tmecom_receive_message(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x8

  v2 = *(_QWORD **)(*(_QWORD *)a1 + 152LL);
  if ( a2 )
  {
    if ( *((_BYTE *)v2 + 168) == 1 )
    {
      dev_err(*v2, "tmecom response pending\n");
    }
    else
    {
      *((_DWORD *)v2 + 30) = *(_DWORD *)a2;
      v3 = *(_QWORD *)(a2 + 8);
      *((_BYTE *)v2 + 168) = 1;
      v2[16] = v3;
    }
  }
  else
  {
    dev_err(*v2, "spurious message received\n");
  }
  return _wake_up(v2 + 17, 1, 1, 0);
}
