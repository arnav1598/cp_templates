ll modpow(ll base, ll exp, ll modulus)
{
  base %= modulus;
  ll result = 1;
  while (exp > 0)
  {
    if (exp & 1)
    	result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result % modulus;
}

//works when base^2 is within range of ll, else use modmul