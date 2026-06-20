void debug_suspend_enabled()
{
  if ( (debug_suspend & 1) == 0 )
    debug_suspend = 1;
}
