__int64 __fastcall signal_session_msg_receipt(__int64 a1, unsigned int a2)
{
  if ( a2 <= 2 )
    complete(a1 + 32LL * a2 + 37584);
  return 0;
}
