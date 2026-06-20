__int64 __fastcall get_ib_base(__int64 a1, int a2)
{
  int v3; // w8

  if ( a2 == 3 )
  {
    v3 = **(_DWORD **)(a1 + 14264);
    if ( (unsigned int)(v3 - 600) > 0xFFFFFF9B )
    {
      return 0;
    }
    else if ( (unsigned int)(v3 - 703) >= 0xFFFFFF99 || v3 == 203264 )
    {
      return 0;
    }
    else
    {
      return qword_17B9F8;
    }
  }
  else if ( a2 == 2 )
  {
    return qword_17B9E8;
  }
  else
  {
    dev_err(*(_QWORD *)a1, "Invalid IB level %d\n", a2);
    return -22;
  }
}
